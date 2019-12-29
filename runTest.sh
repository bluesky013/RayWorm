

Root=$(pwd)

CommonTestDir=${Root}/build/main/Common/test/Debug
cd ${CommonTestDir}
./CommonTest
cd ${Root}

SceneTestDir=${Root}/build/main/Scene/test/Debug

cd ${SceneTestDir}
./SceneTest
cd ${Root}
