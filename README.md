# sleeptracker
The purpose of this project is to apply the capabilities of a ChipKit Max32 micro-controller to a problem I struggle with in my every day life: inconsistent sleep patterns.  The goal is to collect and display data through a text-based survey and vitals sensors that will then give me a better idea of what factors have a greater bearing on the quality of sleep I get. The project, as I envision it now, will come together in 3 main phases:
1. The survey
2. The survey + data visualization software
3. The vitals tracker + survey + data visualization software.  

The survey will be a small program that uses the Basic I/O shield to solicit input from the user.  At night, the user answers a few questions about the details of their day. In the morning, the user answers a few questions about how they slept.  This data is then combined with the data from the sleep timer and saved on a microSD for later processessing. 

The next phase will take this data and present it in a way that will be useful to the user.  The vision I have, though I'm not sure how doable it is, is that a user can select different data fields to be displayed on an axis along side eachother with the intention of seeing if they correlate ex: a user could put data about caffeine consumption up next to sleep duration and if there is an obvious difference in sleep duration on a caffeine day vs a non-caffeine day.

The final phase of the project will be to add vitals tracking sensors to be worn at night during sleep.  The data collected from these sensors will ideally give some sort of insight into how a good nights sleep differs physically from a bad one.  I'm not sure yet whether I will use the sensor data in its raw form or aggregate it into some sort of "sleep-score" to save to SD along with the survey data.

More to come...
