#include "ImGuiLayer.h"

#include "Base.h"
#include "Application.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace core
{
    ImGuiLayer::ImGuiLayer(const std::string &name)
        : Layer(name)
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::onAttach()
    {
        LOG_INFO << "ImGuiLayer onAttach";
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        // Get native window
        Application &app = Application::get();
        GLFWwindow *window = static_cast<GLFWwindow *>(app.getWindow().getNativeWindow());
        if (window == nullptr)
        {
            LOG_FATAL << "Window is nullptr";
        }

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void ImGuiLayer::onDetach()
    {
        LOG_INFO << "ImGuiLayer onDetach";
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::onUpdate(Timestep ts)
    {
        // Get ts
        char buf[32];
        snprintf(buf, sizeof(buf), "FPS: %.1f", 1 / ts);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImDrawList* draw = ImGui::GetForegroundDrawList();
        draw->AddText(
            ImVec2(300, 10),
            IM_COL32(255, 255, 255, 255),
            buf
        );

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::onEvent(Event &e)
    {
    }
}
