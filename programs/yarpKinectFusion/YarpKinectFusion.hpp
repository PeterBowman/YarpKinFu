// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __YARP_KINECT_FUSION__
#define __YARP_KINECT_FUSION__

#include <yarp/os/Port.h>
#include <yarp/os/PortWriterBuffer.h>
#include <yarp/os/RFModule.h>

#include <yarp/dev/IRGBDSensor.h>
#include <yarp/dev/PolyDriver.h>

#include <yarp/sig/PointCloud.h>

#define DEFAULT_LOCAL_PREFIX "/yarpKinectFusion"
#define DEFAULT_PERIOD_MS 20

class YarpKinectFusion : public yarp::os::RFModule
{
public:
    YarpKinectFusion() : iRGBDSensor(nullptr),
                         period(DEFAULT_PERIOD_MS * 0.001)
    { }

    ~YarpKinectFusion()
    { close(); }

    virtual bool configure(yarp::os::ResourceFinder & rf) override;

    virtual double getPeriod() override
    { return period; }

    virtual bool updateModule() override;

    virtual bool close() override;

private:
    yarp::os::Port pointCloudPort;
    yarp::os::PortWriterBuffer<yarp::sig::PointCloud<yarp::sig::DataXYZ>> pointCloudPortWriter;

    yarp::dev::PolyDriver sensorDevice;
    yarp::dev::IRGBDSensor * iRGBDSensor;

    double period;
};

#endif // __YARP_KINECT_FUSION__
