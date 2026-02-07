"""
These tests require another board be flashed with radio controller software and
the connected PC is looping back data `cat /dev/ttyX >/dev/ttyX`
"""

def test_write_increments_packets_received():
    # validate that 1 tx causes another rx on 1 board
    pass

def test_full_loopback():
    # validate that data out = data in
    pass

# Then test with changing doppler params
