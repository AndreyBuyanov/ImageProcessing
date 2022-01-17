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
	explicit Thread(
		IRunnable *method);

	~Thread() override;

	// IThread
	void Start() override;

	void Stop() override;

    [[nodiscard]] bool IsStopped() override;

private:
	IRunnable *m_Method;
	bool m_Stopped;
	unique_ptr<thread> m_ThreadObject;

	void Join();
};

}
