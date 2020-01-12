

Root=$(pwd)

CommonTestDir=${Root}/build/main/Common/test/Debug
cd ${CommonTestDir}
./CommonTest
cd ${Root}

SceneTestDir=${Root}/build/main/SceneDesc/test/Debug
AssetTestDir=${Root}/build/main/Asset/test/Debug
ShapeTestDir=${Root}/build/main/Shape/test/Debug

cd ${SceneTestDir}
./SceneTest
cd ${Root}

cd ${AssetTestDir}
./AssetTest
cd ${Root}

cd ${ShapeTestDir}
./ShapeTest
cd ${Root}

