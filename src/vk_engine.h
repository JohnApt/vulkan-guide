// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>
#include <vector>

class VulkanEngine {
public:

	bool _isInitialized{ false };
	int _frameNumber{ 0 };

	VkExtent2D _windowExtent{ 1700 , 900 };

	struct SDL_Window* _window{ nullptr };

	//Vullkan instance, physical device, and device handles
	VkInstance _instance; //the connection between your application and the Vulkan library
	VkDebugUtilsMessengerEXT _debug_messenger; //debug output handle
	VkPhysicalDevice _chosenGPU; //handle to the GPU the application will use
	VkDevice _device; //logical device handle
	VkSurfaceKHR _surface; //surface handle

	//Swapchain
	VkSwapchainKHR _swapchain; //handle to the swapchain
	VkFormat _swapchainImageFormat; //format of the swapchain (i.e. RGBA, BGRA, etc.)
	std::vector<VkImage> _swapchainImages; //array of images from the swapchain
	std::vector<VkImageView> _swapchainImageViews; //array of image views from the swapchain

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
	void init_swapchain();
};
