#include <stdio.h>
#include "request.h"
#include "io_helper.h"

#include "thread_pool.h"
#include "scheduler.h"

char default_root[] = ".";
static int listen_fd = -1;

// signal handler to close the listening socket gracefully on shutdown
void cleanup(int signal) {
    (void) signal;
    if (listen_fd != -1) {
        close(listen_fd);
        printf("socket closed gracefully\n");
    }
    exit(0);
}

// ./wserver [-d <basedir>] [-p <portnum>] [-t threads] [-b buffers]
int main(int argc, char *argv[]) {
    char *root_dir = default_root;
    int port = 0;

    int c;
    while ((c = getopt(argc, argv, "d:p:")) != -1) {
		switch (c) {
			case 'd':
				root_dir = optarg;
				break;
			case 'p':
				port = atoi(optarg);
				break;
			default:
				fprintf(stderr, "usage: wserver [-d basedir] [-p port]\n");
				exit(1);
		}
	}

    // run out of this directory
    chdir_or_die(root_dir);

	// log current working directory
	char cwd[MAXBUF];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("current working directory: %s\n", cwd);
    } else {
        fprintf(stderr, "getcwd() error\n");
        exit(1);
    }

	// register signal handlers
    signal(SIGINT, cleanup);  // ctrl + c
    signal(SIGTSTP, cleanup); // ctrl + z
    signal(SIGTERM, cleanup); // kill


    // Now, this is a single-threaded webserver that can handle only
    // single request from a client.
    //
    // For Part 1, you should change a single-threaded server to multi-threaded
    // concurrent webserver.
    // This main thread takes a role of starting worker threads and must keep running
    // until any interrupt or signal is coming.
    //
    // For Part 2, you should implement SFF scheduling policy.
    // This main thread now accept requests from clients and push them to your
    // SFF scheduler.
    
    listen_fd = open_listen_fd_or_die(port);

    while (1) {
		struct sockaddr_in client_addr;
		int client_len = sizeof(client_addr);
		int conn_fd = accept_or_die(listen_fd, (sockaddr_t *) &client_addr, (socklen_t *) &client_len);
        request_handle(conn_fd);
	    close_or_die(conn_fd);
    }
    return 0;
}
