#include "OpenGLRender.h"

OpenGLRender::OpenGLRender(const int winWidth, const int winHeight)
  : m_winWidth( winWidth ),
    m_winHeight( winHeight )
{
  std::cout << "OpenGLRender - creating window of (" << m_winWidth << " X " << m_winHeight << ")" << std::endl;

  // Create the main window using the width and height parameters from
  // our command line arguments.
  m_Window = new sf::Window(sf::VideoMode(m_winWidth, m_winHeight, 32), "SFML OpenGL");

  glewInit();

  // ////////////////////////////////////////////////////////////////////////////////////
  // load any geometry you might want here.
  // ////////////////////////////////////////////////////////////////////////////////////

  // ////////////////////////////////////////////////////////////////////////////////////
  // Set the active window before using OpenGL commands. For a
  // single window OpenGL program this really doesn't do much, but
  // if you did have multiple windows, you might need to "render"
  // different things to each window, and thus, you need to make
  // each "window app" active before issuing OpenGL commands.
  m_Window->SetActive();

  // Set color and depth clear value
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

  // Enable Z-buffer read and write
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);

  //
  // Setup the projection
  //
  glViewport(0, 0, m_winWidth, m_winHeight);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float verticalFieldOfView = 60.0; // in degrees
  float aspectRatio = m_winWidth/(float)m_winHeight;
  float nearPlaneDist = 1.0;
  float farPlaneDist = 500.0;
  gluPerspective(verticalFieldOfView, aspectRatio, nearPlaneDist, farPlaneDist);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  // Tell OpenGL which way you've defined your triangles' winding
  glFrontFace(GL_CCW);

  // In this example, we're going to render just a few triangles to
  // show how its done.

  glGenBuffers(2, &m_triangleVBO);///////
  glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);

  int num_of_shapes = 2;
  //m_numVertices = 3;
  m_numVertices = 3 * num_of_shapes;
  int numFloatsPerVertex = 3;
  int numColors = 3;  // for non-material shading
  int numFloatsPerColor = 3;
  int numTextureCoords = 3;
  int numFloatsPerTextureCoord = 2;


  float* host_VertexBuffer = new float[ m_numVertices * numFloatsPerVertex * numColors * numFloatsPerColor * 2 * 3 * num_of_shapes];

  int tIdx = 0;

  // ////////////////////////
  // V0
  // The vertex data
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 2.5f;
  host_VertexBuffer[ tIdx++ ] = -8.0f;

  // then it's color
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 1.0f;

  // then, the texture coordinate if it has one
  host_VertexBuffer[ tIdx++ ] = 0.0;
  host_VertexBuffer[ tIdx++ ] = 0.0;

  // ////////////////////////
  // V1
  // the next vertex data
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -5.0f;

  // it's color
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 1.0f;

  // then, the texture coordinate
  host_VertexBuffer[ tIdx++ ] = 1.0;
  host_VertexBuffer[ tIdx++ ] = 0.0;

  // ////////////////////////
  // V2
  // the 3rd vertex
  host_VertexBuffer[ tIdx++ ] = 2.5f;
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -5.0f;

  // it's color
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 1.0f;

  // then, the texture coordinate
  host_VertexBuffer[ tIdx++ ] = 0.5;
  host_VertexBuffer[ tIdx++ ] = 0.5;


  //------Second Triangle------------------------
  // ////////////////////////
  // V0
  // The vertex data
  host_VertexBuffer[ tIdx++ ] = -5.0f;
  host_VertexBuffer[ tIdx++ ] = 2.5f;
  host_VertexBuffer[ tIdx++ ] = -10.0f;

  // then it's color
  host_VertexBuffer[ tIdx++ ] = 1.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;

  // then, the texture coordinate if it has one
  host_VertexBuffer[ tIdx++ ] = 0.0;
  host_VertexBuffer[ tIdx++ ] = 0.0;

  // ////////////////////////
  // V1
  // the next vertex data
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -5.0f;

  // it's color
  host_VertexBuffer[ tIdx++ ] = 1.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;

  // then, the texture coordinate
  host_VertexBuffer[ tIdx++ ] = 1.0;
  host_VertexBuffer[ tIdx++ ] = 0.0;

  // ////////////////////////
  // V2
  // the 3rd vertex
  host_VertexBuffer[ tIdx++ ] = 2.5f;
  host_VertexBuffer[ tIdx++ ] = -2.5f;
  host_VertexBuffer[ tIdx++ ] = -5.0f;

  // it's color
  host_VertexBuffer[ tIdx++ ] = 1.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;
  host_VertexBuffer[ tIdx++ ] = 0.0f;

  // then, the texture coordinate
  host_VertexBuffer[ tIdx++ ] = 0.5;
  host_VertexBuffer[ tIdx++ ] = 0.5;

  //-----------------------------
  int numBytes = m_numVertices * numFloatsPerVertex * numColors * numFloatsPerColor * 2 * 3 * sizeof(float) * num_of_shapes;
  glBufferData(GL_ARRAY_BUFFER, numBytes, host_VertexBuffer, GL_STATIC_DRAW);
  delete [] host_VertexBuffer;

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLRender::run()
{
  // Start rendering loop
  while (m_Window->IsOpened()) {

    // Process events
    sf::Event Event;
    while (m_Window->GetEvent(Event)) {

      // Close window : exit
      if (Event.Type == sf::Event::Closed) {
	m_Window->Close();
      }

      // Escape key : exit
      if ((Event.Type == sf::Event::KeyPressed)
	  && (Event.Key.Code == sf::Key::Escape)) {
	m_Window->Close();
      }

      // Resize event : adjust viewport
      if (Event.Type == sf::Event::Resized) {
	glViewport(0, 0, Event.Size.Width, Event.Size.Height);
      }

      // Check for W, A, S, D keys...
      if ((Event.Type == sf::Event::KeyPressed)
	  && (Event.Key.Code == sf::Key::W)) {
	// Move your camera forward
      }

      if (Event.Type == sf::Event::MouseButtonPressed) {
	if (Event.MouseButton.Button == sf::Mouse::Left) {
	  // Do something with the mouse data
	}
      }
    }

    // Set the active window before using OpenGL commands. For a
    // single window OpenGL program this really doesn't do much, but
    // if you did have multiple windows, you might need to "render"
    // different things to each window, and thus, you need to make
    // each "window app" active before issuing OpenGL commands.
    m_Window->SetActive();

    // Place your OpenGL calls here that allow the screen to be
    // refreshed each time this loop is executed.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);

    glVertexPointer(3, GL_FLOAT, 8 * sizeof(float), 0);
    glColorPointer(3, GL_FLOAT, 8 * sizeof(float), (GLvoid*)(3*sizeof(float)));
    glTexCoordPointer(2, GL_FLOAT, 8 * sizeof(float), (GLvoid*)(6*sizeof(float)));

    glDrawArrays(GL_TRIANGLES, 0, m_numVertices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Finally, display rendered frame on screen - this is the command
    // that tells OpenGL to actually refresh the window you're looking
    // at with what you wrote to memory in the commands above.
    m_Window->Display();
  }
}
