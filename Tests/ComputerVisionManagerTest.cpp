//
// Created by vboxuser on 12/12/23.
//
#include "gtest/gtest.h"
#include "CameraModule/ComputerVisionManager.cpp"

using namespace CameraModule;


class ComputerVisionManagerTest : public ::testing::Test {

protected:
    ComputerVisionManager * computerVisionManager;
    virtual void SetUp() {
        computerVisionManager = new ComputerVisionManager();
    }

    virtual void TearDown() {
        delete computerVisionManager;
    }

};

TEST_F(ComputerVisionManagerTest, TestCreateCVManager) {
    auto * tempComputerVisionManager = new ComputerVisionManager();
    EXPECT_NE(nullptr, tempComputerVisionManager);
    delete tempComputerVisionManager;
}

TEST_F(ComputerVisionManagerTest, TestCompareTagResponse) {
    string target = "Toilet";
    string Response = R"({"status":200,"message":"Success","data":{"error":0,"type":"objects","objects":[{"name":"Indoors","confidence":99.98857116699219,"coordinates":[]},{"name":"Bathroom","confidence":97.97352600097656,"coordinates":[]},{"name":"Room","confidence":97.97352600097656,"coordinates":[]},{"name":"Toilet","confidence":97.97352600097656,"coordinates":[]}],"quota":876}})";
    json jsonResponse = json::parse(Response);
    auto result = computerVisionManager->CompareTargetResponse(target,jsonResponse.dump());
    EXPECT_EQ(result,0);
}
