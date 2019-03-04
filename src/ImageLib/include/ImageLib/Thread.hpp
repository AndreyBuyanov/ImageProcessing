#pragma once

#include "ImageLib/IThread.hpp"

#include <memory>
#include <thread>

using std::thread;
using std::unique_ptr;

namespace ImageLib
{

class Thread:
	public IThread
{
public:
	Thread(
		IRunnable *method);

	~Thread();

	// IThread
	void Start();

	void Stop();

	bool IsStopped();

private:
	IRunnable *m_Method;
	bool m_Stopped;
	unique_ptr<thread> m_ThreadObject;

	void Join();
};

}
