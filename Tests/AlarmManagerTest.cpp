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
        json m_jsonAlarms = json::parse(DEFAULT_ALARM_STRING);
        FileUtil::WriteToFile(FILES_PATH, ALARM_FILE_NAME, m_jsonAlarms);
        delete alarmManager;
    }

};

TEST_F(AlarmManagerTest, TestCreateAlarmManager){
    auto * tempAlarmManager = new AlarmManager();
    EXPECT_NE(nullptr, tempAlarmManager);
    delete tempAlarmManager;
}

TEST_F(AlarmManagerTest, TestGetAlarms){
    json m_jsonAlarms = json::parse(DEFAULT_ALARM_STRING);
    string alarmsFromManager =alarmManager->GetAlarms();
    ASSERT_STREQ(m_jsonAlarms.dump().c_str(), alarmsFromManager.c_str());
}

TEST_F(AlarmManagerTest, TestUpdateAlarmsAndGet) {
    alarmManager->UpdateAlarms(alarms);
    string alarmsFromManager =alarmManager->GetAlarms();
    ASSERT_STREQ(alarms.c_str(), alarmsFromManager.c_str());
}