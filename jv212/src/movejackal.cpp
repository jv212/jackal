/*
 * This source file was written to control the manipulator portion of an aerial manipulation platform (Multirotor and coupled
 * 5 degree of freedom manipulator. This code will broadcast transforms of all manipulator frames to the /tf topic in ROS
 * A user can control each servo using the keyboard keys Q,A,W,S,E,D,R,F,Y,H and the user may switch from manual to autonomous
 * tracking modes using 1 and 2 keys. Mode 1 is default and allows manual control, mode 2 is autonomous.
 * Hardware includes an Arbotix-M Controller with AX-12 servos and a usb-webcam.
 *
 * written by: John Vargas
 *
 */

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <math.h>
#include <keyboard/Key.h>
#include <geometry_msgs/Twist.h>
#define RATE_LOOP 0.1
#define XVEL 1
#define ZVEL 1

#define Q_KEY 113
#define A_KEY 97
#define W_KEY 119
#define S_KEY 115
#define E_KEY 101
#define D_KEY 100
#define R_KEY 114
#define F_KEY 102
#define T_KEY 116
#define G_KEY 103
#define Y_KEY 121
#define H_KEY 104
#define ONE_KEY 49
#define TWO_KEY 50
#define THREE_KEY 51


class test{
	public:
		test();

	private:

        ros::NodeHandle nh;                         //ROS Node Handle
        ros::Subscriber keyup_sub;                  //subscriber for float topic
				ros::Subscriber keydown_sub;                  //subscriber for float topic
				ros::Publisher vel_pub;                   //Publishes float
        ros::Timer timer;                           //ROS timer object

				geometry_msgs::Twist vel;                        //var for float test

        //callback defines
				void keydown_cb(const keyboard::KeyConstPtr& keydown);
		   	void keyup_cb(const keyboard::KeyConstPtr& keyup);
				void timer_cb(const ros::TimerEvent& event);
};

test::test(){
    	timer = nh.createTimer(ros::Duration(RATE_LOOP), &test::timer_cb, this);
			keyup_sub = nh.subscribe<keyboard::Key>("/keyboard/keyup", 1, &test::keyup_cb, this);
			keydown_sub = nh.subscribe<keyboard::Key>("/keyboard/keydown", 1, &test::keydown_cb, this);
			vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
			vel.linear.x=0;
			vel.linear.y=0;
			vel.linear.z=0;
			vel.angular.x=0;
			vel.angular.y=0;
			vel.angular.z=0;
}


void test::timer_cb(const ros::TimerEvent& event){
	vel_pub.publish(vel);
}

void test::keyup_cb(const keyboard::KeyConstPtr& keyup){
    	int x = keyup -> code;
			switch(x){
	         case Q_KEY:

	             break;
	         case A_KEY:
					 vel.angular.z=0;
	             break;
	         case W_KEY:
					 vel.linear.x=0;

	             break;
	         case S_KEY:
					 vel.linear.x=0;
	             break;
	         case E_KEY:

	             break;
	         case D_KEY:
					 vel.angular.z=0;
	             break;
	         case R_KEY:

	             break;
	         case F_KEY:

	             break;
	         case T_KEY:

	             break;
	         case G_KEY:

	             break;
	         case Y_KEY:

	             break;
	         case H_KEY:

	             break;
	     }
}

void test::keydown_cb(const keyboard::KeyConstPtr& keydown){
	int x = keydown -> code;
	switch(x){
		 	case Q_KEY:

				 break;
		 case A_KEY:
		 		vel.angular.z=ZVEL;
				 break;
		 case W_KEY:
		 		vel.linear.x=XVEL;
				 break;
		 case S_KEY:
		 		vel.linear.x=-XVEL;
				 break;
		 case E_KEY:

				 break;
		 case D_KEY:
		 vel.angular.z=-ZVEL;
				 break;
		 case R_KEY:

				 break;
		 case F_KEY:

				 break;
		 case T_KEY:

				 break;
		 case G_KEY:

				 break;
		 case Y_KEY:

				 break;
		 case H_KEY:

				 break;
 }



}

int main(int argc, char **argv){
	ros::init(argc, argv, "test");
	ROS_INFO_STREAM("testTimer Node Active!");
	test t;

	while(ros::ok()){
		ros::spinOnce();
	}
}
