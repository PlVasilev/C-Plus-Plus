#ifndef AVERAGE_AGGREGATOR_H
#define AVERAGE_AGGREGATOR_H

#include "Aggregator.h"

using namespace std;

class AverageAggregator : public StreamAggregator
{
	int sum;
	
public:
	AverageAggregator(istringstream& input) : StreamAggregator(input), sum(0) {}
	virtual void aggregate(int next) override {
		
		StreamAggregator::aggregate(next);
		this->sum += next;
		this->aggregationResult = sum/ StreamAggregator::getNumAggregated();
	}
};

#endif // !AVERAGE_AGGREGATOR_H