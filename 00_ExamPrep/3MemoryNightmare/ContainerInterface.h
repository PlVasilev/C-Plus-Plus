#ifndef CONTAINER_INTERFACE_H_
#define CONTAINER_INTERFACE_H_

class ContainerInterface
{

public:
    ContainerInterface() = default;
    virtual ~ContainerInterface() = default;

    virtual std::size_t getOccupiedMemory() const = 0;
};


#endif /* CONTAINER_INTERFACE_H_ */