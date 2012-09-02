#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW01Part2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	void HW01Part2App::drawCircle(uint8_t* pixels, int center_x, int center_y, int radius, Color8u color);

	private:
	Surface* mySurface_;
	uint8_t* dataArray;

	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kTextureSize=1024;
};

void HW01Part2App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void HW01Part2App::setup()
{
	mySurface_ = new Surface(kTextureSize,kTextureSize,false);


	//Surface dog(loadImage( loadResource(RES_DOG) ));
}

void HW01Part2App::drawCircle(uint8_t* pixels, int center_x, int center_y, int radius, Color8u color)
{
	for(int y = center_y - radius; y <= center_y + radius; y++)
	{
		for(int x = center_x; x <= center_x + 2*radius; x++)
		{
			//Bounds test, to make sure we don't access array out of bounds
			if(y < 0 || x < 0 || x >= kAppWidth || y >= kAppHeight) continue;
					int offset = 3*(x + y*kTextureSize);
					//By blending the colors I get a semi-transparent effect
					pixels[offset] = color.r;
					pixels[offset+1] = color.g;
					pixels[offset+2] = color.b;
		}
	}
}

void HW01Part2App::mouseDown( MouseEvent event )
{

}

void HW01Part2App::update()
{
	uint8_t* dataArray = (*mySurface_).getData();
	drawCircle(dataArray, 400, 400, 50, Color8u(255,0,0));
}

void HW01Part2App::draw()
{
	gl::draw(*mySurface_); 
}

CINDER_APP_BASIC( HW01Part2App, RendererGl )
