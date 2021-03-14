#ifndef SUM_AGGREGATOR_H
#define SUM_AGGREGATOR_H

#include "Aggregator.h"

using namespace std;

class SumAggregator : public StreamAggregator
{
	int sum;

public:
	SumAggregator(istringstream& input) : StreamAggregator(input), sum(0) {}
	virtual void aggregate(int next) override {

		StreamAggregator::aggregate(next);
		this->sum += next;
		this->aggregationResult = sum;
	}
};

#endif // !SUM_AGGREGATOR_H