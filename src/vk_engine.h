// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>

class VulkanEngine {
public:
	
	bool _isInitialized{ false };
	int _frameNumber {0};

	VkExtent2D _windowExtent{ 1700 , 900 };

	struct SDL_Window* _window{ nullptr };
	
	//Vullkan instance handles
	VkInstance _instance; //the connection between your application and the Vulkan library
	VkDebugUtilsMessengerEXT _debug_messenger; //debug output handle
	VkPhysicalDevice _chosenGPU; //handle to the GPU the application will use
	VkDevice _device; //logical device handle
	VkSurfaceKHR _surface; //surface handle

	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();
	
private:
	void init_vulkan();
};
