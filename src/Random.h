/*
 * Random.h
 *
 *  Created on: May 29, 2018
 *      Author: adolfo
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

class Random
{
public:

	static void Seed()
	{
		static std::random_device r;
		static std::seed_seq seed { r(), r(), r(), r(), r(), r(), r(), r() };
		rng_engine.seed(seed);

		mSeeded = true;
	}

	// Generate random number between low and high (both included)
	static int GetRandomInt(int low, int high)
	{
		if (!mSeeded)
			Seed();

		return std::uniform_int_distribution<int>(low, high)(rng_engine);
	}
private:
	static bool mSeeded;
	static std::mt19937 rng_engine;
};

bool Random::mSeeded;
std::mt19937 Random::rng_engine;

#endif /* RANDOM_H_ */
