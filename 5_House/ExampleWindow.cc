
#include "ExampleWindow.h"

#include <cmath>

static constexpr double Pi = acos(-1.);

#include "Primitives.h"

double coeff=0.25;


ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  _crate_texture("crate_tex.png"),
  _snowman_texture("snowman_tex.png"),
  _tree_texture("tree_tex.png"),
  _carrot_texture("carrot_tex.png")
{

}

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	// ����� ���� ������� ������ �����
	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION); // ����� ���������� ������� ��������
	gluPerspective(45.,
			double(width()) / double(height()),
			0.1, 60.0);
	glMatrixMode(GL_MODELVIEW); // ����� ���������� ������� ������-����
}

void ExampleWindow::render()
{
	// ������� ������ �����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); // ������ ������� ������� �� ���������

	gluLookAt(
			0., 20., 12,
			0.0, 0.0, 0.0,
			0., 0., 1.);
//sin(360)*12
	//glRotated(_angle, 0., 0., 1.);
	glEnable(GL_TEXTURE_2D);
	_crate_texture.bind();

	glPushMatrix();
	        glRotated(90., 0., 0., 1.);
	        glTranslated(-6.,0.,0.);
	            _cube.draw();
	    glPopMatrix();

	glPushMatrix();
		    glRotated(90., 0., 0., 1.);
		    glTranslated(-6.,-3.,0.);
		       _cube.draw();
	    glPopMatrix();

	glPushMatrix();
	        glRotated(90., 0., 0., 1.);
	        glTranslated(-6.,3.,0.);
	            _cube.draw();
	    glPopMatrix();

	glPushMatrix();
		    glRotated(90., 0., 0., 1.);
		        glTranslated(-6.,-6.,0.);
		            _cube.draw();
		    glPopMatrix();

	glPushMatrix();
		    glRotated(90., 0., 0., 1.);
		    glTranslated(-6.,6.,0.);
		         _cube.draw();
		glPopMatrix();

	glPushMatrix();
			glRotated(45., 0., 0., 1.);
			glTranslated(-10.,3.,0.);
			     _cube.draw();
	    glPopMatrix();

	glPushMatrix();
		    glRotated(135., 0., 0., 1.);
			glTranslated(-10.,-3.,0.);
				_cube.draw();
		glPopMatrix();

	glPushMatrix();
		    glRotated(0., 0., 0., 1.);
		    glTranslated(-11.,-2.,0.);
		        _cube.draw();
		glPopMatrix();

	glPushMatrix();
			glRotated(0., 0., 0., 1.);
			glTranslated(-11.,1.,0.);
			    _cube.draw();
	    glPopMatrix();

	glPushMatrix();
			glRotated(180., 0., 0., 1.);
			glTranslated(-11.,2.,0.);
			   _cube.draw();
	    glPopMatrix();

	glPushMatrix();
			glRotated(180., 0., 0., 1.);
			glTranslated(-11.,-1.,0.);
				   _cube.draw();
		    glPopMatrix();


	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(6.,0.,-1.);
			glScaled(0.8, 0.8, 0.8);
		       draw_cylinder(12);
		glPopMatrix();

    _tree_texture.bind();
	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(6.,0.,0.6);
			glScaled(1.2, 1.2, 1.2);
			draw_cone(18);
		glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(6.,0.,1.2);
			glScaled(1.1, 1.1, 1.1);
				draw_cone(18);
		glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(6.,0.,1.8);
			glScaled(0.9, 0.9, 0.9);
				draw_cone(18);
		glPopMatrix();

		_snowman_texture.bind();
	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(1.,3.,z1);
			glScaled(1.5, 1.5, 1.5);
			draw_sphere_smooth(180,60);
		glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(1.,3.,z2);
			glScaled(1.3, 1.3, 1.3);
			draw_sphere_smooth(180,60);
		glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(1.,3.,z3);
			glScaled(1.1, 1.1, 1.1);
			draw_sphere_smooth(180,60);
		glPopMatrix();

		glPushMatrix();
				glRotated(90., 0., 0., 1.);
				glTranslated(1.,-3.,z1);
				glScaled(1.5, 1.5, 1.5);
				draw_sphere_smooth(180,60);
			glPopMatrix();

		glPushMatrix();
				glRotated(90., 0., 0., 1.);
				glTranslated(1.,-3.,z2);
				glScaled(1.3, 1.3, 1.3);
				draw_sphere_smooth(180,60);
			glPopMatrix();

		glPushMatrix();
				glRotated(90., 0., 0., 1.);
				glTranslated(1.,-3.,z3);
				glScaled(1.1, 1.1, 1.1);
				draw_sphere_smooth(180,60);
			glPopMatrix();

	/*	glPushMatrix();
				glRotated(120., 0., 6., 4.);
				glTranslated(1.5,1.,-4.5);
				draw_pyramid(18);
			glPopMatrix();*/
			_carrot_texture.bind();

			glPushMatrix();
					glTranslated(2.8,1.2,z_carrot);
					glRotated(45., 0., 0., 1.);
					glRotated(180., 0., 1., 1.);
					glScaled(0.8, 0.8, 0.8);
					draw_pyramid(18);
				glPopMatrix();

			glPushMatrix();
					glTranslated(-2.8,1.2,z_carrot);
					glRotated(-45., 0., 0., 1.);
					glRotated(180., 0., 1., 1.);
					glScaled(0.8, 0.8, 0.8);
					draw_pyramid(18);
				glPopMatrix();

	   _crate_texture.bind();
	   _ground.draw();
	//_cube.draw();
}

void ExampleWindow::do_logic()
{
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

	z1 += coeff;
	z2 += coeff;
	z3 += coeff;
	z_carrot += coeff;
	if (z1<=-0.6 || z1>=0.3){
		coeff*=-1;
	}
	//if (z1<=0.1 || z1>=1.0)

	//_camera_z = sin(_angle / 180. * Pi) * 10.;
}





