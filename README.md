
# Solaris Backend
[![244326655-332221555363473-4636031536199997176-n.jpg](https://i.postimg.cc/pLmcczpd/244326655-332221555363473-4636031536199997176-n.jpg)](https://postimg.cc/Mn8Yvc0k)

The Arduino source code of our Solaris Sun Tracker. This IOT device fetches the optimum tilt angle from Solaris data and moves the servo motor according to that.


### Challenges
---
Although Solar Panels that track the sun already exists, there are some challenges implementing those and gaining financial benefits. Team Solaris tried to find a better alternative to the traditional Solar Trackers and this Arduino is the first step to that path: 
  - #### Setup Cost
	  Panels with Solar Trackers are built different. They are costlier than the traditional solar panels and hard to set up. Solaris' Arduino solution can deal with this problem because, on industrial production, the robotic hand system will be cheap to buy, and any traditional panel can be attached to it, to gain the maximum out of the solar panel.
  - #### Maintenance
	  Traditional solar trackers work all day. It tracks the sun continuously and keeps moving all the time. This ends up wasting a significant portion of the solar energy it gained. Since Solaris API can already track the optimum angle, where the panel doesn't need to move at all, and still can gain optimum energy, the necessity of solar trackers is nil. Still the Arduino we provide can create a win-win situation, since it tracks the sun every two hours, using Solaris API and moves the panel if needed. 

### Dependencies
---
We have used a few modules to create our Solaris Arduino demonstration. They are listed below:
1. Servo library
2. ESP8266 library
### Working Method
---
The Arduino module works in three steps -

1. Arduino calls api from Solaris Backend using the ESP8266 library. And extracts the optimum tilt angle from that.
2. The Servo module then moves the servo motor towards that tilt angle and tracks the sun.
3. Lastly, the Arduino waits for 2 hours to repeat task 1 and 2, and makes the Arduino a perfect demonstration of Solaris perfection!

### Resources
---
* Solaris web app : [Solaris web homepage](https://solaris-bd.web.app/)*
* Solaris web app repo : [Github repo for Solaris web app](https://github.com/SalmanSayeed79/Solaris-BD)
* Solaris Mobile app : [Apk drive link](https://drive.google.com/file/d/170HMrigXFpZwzHW3F4FIAJt-gC9HfU5Z/view?usp=sharing)
* Solaris Mobile app repo: [Github repo for solaris mobile app](https://github.com/zarifikram/SOLARIS)
* Solaris IOT module : [Github repo for Solaris IOT code](https://github.com/pptx704/solaris-servo-control)

### Reference
---
NASA POWER API Homepage : [NASA POWER API](https://power.larc.nasa.gov/)
Python Flask : [Flask Website](https://flask.palletsprojects.com/en/2.0.x/)
