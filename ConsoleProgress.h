#ifndef CONSOLE_PROGRESS_H
#define CONSOLE_PROGRESS_H

#include <string>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>

class ConsoleProgress
{
public:
	ConsoleProgress(size_t total, char complete = '=', char incomplete = '-') :
		total_(total),
		complete(complete),
		incomplete(incomplete),
		cur(0)
	{
		startTime = std::chrono::steady_clock::now();
	}

	void step(size_t v = 1)
	{
		cur += v;
		if (cur > total_)
			cur = total_;
	}
	void set(size_t v)
	{
		cur = v;
		if (cur > total_)
			cur = total_;
	}

	size_t current() const
	{
		return cur;
	}

	size_t total() const
	{
		return total_;
	}

	std::string bar(size_t width) const
	{
		if (!width)
			return "";

		int part = static_cast<int>(std::round(getPercent() * width / 100.f));
		part = std::min<int>(std::max<int>(part, 0), width);

		std::string result(width, incomplete);
		for (int i = 0; i < part; ++i)
			result[i] = complete;

		return result;
	}

	std::string percent() const
	{
		return std::to_string(static_cast<int>(std::round(getPercent()))) + "%";
	}

	std::string elapsed() const
	{
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(1) << getElapsed();
		return ss.str();
	}

	std::string eta() const
	{
		float eta = getEta();
		if (std::isnan(eta))
			return "-.-";

		std::ostringstream ss;
		ss << std::fixed << std::setprecision(1) << eta;
		return ss.str();
	}

	float getPercent() const
	{
		return total_ ? 100.f * cur / total_ : 100.f;
	}

private:
	float getElapsed() const
	{
		std::chrono::duration<float> sec = std::chrono::steady_clock::now() - startTime;
		return sec.count();
	}
	float getEta() const
	{
		float p = getPercent();
		if (p < 0.01)
			return NAN;
		float e = getElapsed();
		if (e < 0.01)
			return NAN;

		float totalTime = e / (p / 100.f);
		float eta = totalTime - e;

		return eta;
	}
	size_t total_;
	char complete;
	char incomplete;
	std::chrono::steady_clock::time_point startTime;
	size_t cur;
};

#endif
