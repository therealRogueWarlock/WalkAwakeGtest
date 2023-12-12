//
// Created by vboxuser on 12/12/23.
//
#include "gtest/gtest.h"
#include "AlarmModule/AlarmManager.cpp"
#include <gmock/gmock.h>

using namespace AlarmModule;


class AlarmManagerTest : public ::testing::Test {

protected:



    string alarms = R"({"alarms":[{"Day":"Sunday","Enabled":false,"Time":"00:00"},{"Day":"Monday","Enabled":true,"Time":"11:38"},{"Day":"Tuesday","Enabled":true,"Time":"11:38"},{"Day":"Wednesday","Enabled":false,"Time":"00:00"},{"Day":"Thursday","Enabled":false,"Time":"00:00"},{"Day":"Friday","Enabled":true,"Time":"11:38"},{"Day":"Saturday","Enabled":false,"Time":"00:00"}]})";



    AlarmManager * alarmManager;

    virtual void SetUp() {
        alarmManager = new AlarmManager();
    }

    virtual void TearDown() {
        //FileUtil::WriteToFile(FILES_PATH, ALARM_FILE_NAME, DEFAULT_ALARM_STRING);
    }

};
TEST_F(AlarmManagerTest, TestCreateAlarmManager){
    auto * tempAlarmManager = new AlarmManager();
    EXPECT_NE(nullptr, tempAlarmManager);
    delete tempAlarmManager;
}



TEST_F(AlarmManagerTest, TestUpdateAlarms) {
    alarmManager->UpdateAlarms(alarms);
    string alarmsFromManager =alarmManager->GetAlarms();
    cout << alarms;
    cout << alarmsFromManager;
    ASSERT_STREQ(alarms.c_str(), alarmsFromManager.c_str());
}
