def test_send_command(fprime_test_api):
    """ Ensure commanding works as expected

    Tests that commands may be sent and the expected command severity events are returned.
    """
    fprime_test_api.send_and_assert_command("CdhCore.cmdDisp.CMD_NO_OP", max_delay=0.1)
    assert fprime_test_api.get_command_test_history().size() == 1
