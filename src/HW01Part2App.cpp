#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW01Part2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW01Part2App::setup()
{
}

void HW01Part2App::mouseDown( MouseEvent event )
{
}

void HW01Part2App::update()
{
}

void HW01Part2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW01Part2App, RendererGl )
