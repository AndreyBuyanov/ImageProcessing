#include "ImageLib/Thread.hpp"

namespace ImageLib
{

class ThreadFunc
{
public:
	ThreadFunc(
		IRunnable *method,
		bool *stoppedFlag) :
		m_Method(method),
		m_StoppedFlag(stoppedFlag) {}

	void operator() ()
	{
		m_Method->Run();
		(*m_StoppedFlag) = true;
	}

private:
	IRunnable *m_Method;
	bool *m_StoppedFlag;
};

Thread::Thread(
	IRunnable *method) :
	m_Method(method),
	m_Stopped(true) {}

Thread::~Thread()
{
	Stop();
}

void Thread::Start()
{
	if (m_Stopped) {
		Join();
		m_ThreadObject.reset(new thread(ThreadFunc(m_Method, &m_Stopped)));
		m_Stopped = false;
	}
}

void Thread::Stop()
{
	m_Stopped = true;
	Join();
}

bool Thread::IsStopped()
{
	return m_Stopped;
}

void Thread::Join()
{
	if (m_ThreadObject.get() && m_ThreadObject->joinable()) {
		m_ThreadObject->join();
	}
}

}