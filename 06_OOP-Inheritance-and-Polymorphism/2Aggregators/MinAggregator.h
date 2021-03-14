#ifndef MIN_AGGREGATOR_H
#define MIN_AGGREGATOR_H

#include "Aggregator.h"

using namespace std;

class MinAggregator : public StreamAggregator
{
	int min;

public:
	MinAggregator(istringstream& input) : StreamAggregator(input), min(INT_MAX) {}
	virtual void aggregate(int next) override {

		StreamAggregator::aggregate(next);
		if (this-> min > next)
		{
			this->min = next;
		}
		this->aggregationResult = min;
	}
};

#endif // !MIN_AGGREGATOR_H