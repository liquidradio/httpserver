﻿#pragma once

#ifdef WIN32
	#include <WS2tcpip.h>

	::TCHAR myWndClassName[];

    #ifdef SIGTERM
        #undef SIGTERM
        #define SIGTERM (WM_USER + 15)
    #endif

    #ifdef SIGINT
        #undef SIGINT
        #define SIGINT (WM_USER + 2)
    #endif

    #ifndef SIGUSR1
        #define SIGUSR1 (WM_USER + 10)
    #endif

    #ifndef SIGUSR2
        #define SIGUSR2 (WM_USER + 12)
    #endif
#elif POSIX
	#include <sys/types.h>
#else
	#error "Undefine platform"
#endif

#include <string>
#include <ctime>
#include <thread>

namespace System
{
#ifdef WIN32
	typedef ::SOCKET native_socket_type;
#elif POSIX
	typedef int native_socket_type;
#else
	#error "Undefine platform"
#endif

#ifdef WIN32
	typedef ::DWORD native_processid_type;
#elif POSIX
	typedef ::pid_t native_processid_type;
#else
	#error "Undefine platform"
#endif

	native_processid_type getProcessId();

	bool changeCurrentDirectory(const std::string &dir);

	bool isProcessExists(const native_processid_type pid);

	bool sendSignal(const native_processid_type pid, const int signal);

	bool isDoneThread(const std::thread::native_handle_type handle);

	std::string getTempDir();

	bool isFileExists(const std::string &fileName);

	bool getFileSizeAndTimeGmt(const std::string &filePath, size_t *fileSize, time_t *fileTime);

	void filterSharedMemoryName(std::string &memName);
};