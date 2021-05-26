#pragma once

//#include "vld.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <typeinfo>
#include <algorithm>
#include <sstream> 
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <thread>
#include <utility>
#include <memory>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <deque>
#define _USE_MATH_DEFINES
#include <cmath>

//SFML
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

//TGUI
#include <TGUI/TGUI.hpp>

//SFMLDragonBones
#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>

#include "Src/Global/Config.h"
#include "Src/Utility/PhysicsWorld.h"
#include "Characteristics.h"

extern Config config;