#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>
#include <memory>

#include "States/StateBase.h"
#include "Renderer/RenderMaster.h"

#include "Context.h"
#include "Camera.h"

float extern g_timeElapsed;

class Application {

public:
  Application(const Config &config);

  void runLoop();

  template<typename T, typename... Args>
  void pushState(Args &&... args) {
    m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    auto &s = m_states.back();
    s->onOpen();
  }

  Camera &getCamera() { return m_camera; }

  const sf::RenderWindow &getWindow() const { return m_context.window; }

  void grabMouse();

  void releaseMouse();

private:
  void handleEvents();

  bool m_isMouseGrabbed;

  std::vector<std::unique_ptr<StateBase>> m_states;

  Context m_context;
  RenderMaster m_masterRenderer;
  Camera m_camera;

  const Config &m_config;

  bool m_isPopState = false;
};

#endif // APPLICATION_H_INCLUDED
