#pragma once
#include <cstdint>
#include <vector>
#include <raylib.h>

struct vectorHash
{
    std::size_t operator()(std::vector<uint32_t> const &vec) const
    {
        std::size_t seed = vec.size();
        for (auto &i : vec)
        {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

struct pairhash
{
  public:
    template <typename T, typename U> std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};



template<typename... Args, typename Func>
	float timeFunction(Args&&... args, Func&& func)
	{
		float startTime = GetTime();
		func(std::forward<Args>(args)...);
		float endTime = GetTime();
		return endTime - startTime;
	}
