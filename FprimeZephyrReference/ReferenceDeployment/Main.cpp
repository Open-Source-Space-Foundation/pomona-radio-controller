// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for CLI-based systems (Linux, macOS)
//
// ======================================================================
// Used to access topology functions
#include <FprimeZephyrReference/ReferenceDeployment/Top/ReferenceDeploymentTopology.hpp>
#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

const struct device* controlSerial = DEVICE_DT_GET(DT_NODELABEL(cdc_acm_uart0));
const struct device* dataSerial = DEVICE_DT_GET(DT_NODELABEL(cdc_acm_uart1));

int main(int argc, char* argv[]) {
    // ** DO NOT REMOVE **//
    //
    // This sleep is necessary to allow the USB CDC ACM interface to initialize before
    // the application starts writing to it.
    k_sleep(K_MSEC(3000));

    Os::init();
    // Object for communicating state to the topology
    ReferenceDeployment::TopologyState inputs;
    inputs.controlUartDevice = controlSerial;
    inputs.dataUartDevice = dataSerial;
    inputs.controlUartBaudRate = 115200;
    inputs.dataUartBaudRate = 115200;

    // Setup, cycle, and teardown topology
    ReferenceDeployment::setupTopology(inputs);
    ReferenceDeployment::startRateGroups();  // Program loop
    ReferenceDeployment::teardownTopology(inputs);
    return 0;
}
