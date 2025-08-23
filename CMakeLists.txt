cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        read_save_from_file.h
        clsString.h
        clsDate.h
        clsUtility.h
        clsPeriod.h
        clsPerson.h
        clsBankClient.h
        clsBankScreen.h
        clsMainMenuScreen.h
        clsShowAllClientsScreen.h
        clsAddNewClientScreen.h
        clsUpdateClientScreen.h
        clsFindClientScreen.h
        clsDeleteClientScreen.h
        clsTransactionMenuScreen.h
        clsDepositScreen.h
        clsWithdrawScreen.h
        clsTotalbalancesScreen.h
        clsManageUsersScreen.h
        clsBankUser.h
        clsListAllUsersScreen.h
        clsAddNewUserScreen.h
        clsDeleteUserScreen.h
        clsUpdateUserScreen.h
        clsFindUserScreen.h
        clsLoginScreen.h
        global.h
        clsLog.h
)
