## Installing Particle Workbench and VS Code

#### This installation tutorial assumes that you have done the following:

1. [set up a new Particle.io account](particle.io/signup) with your information and have a login. 
1. [registered and set up your *Photon 2* device](https://setup.particle.io/) with the Particle.io platform, associated with said account.
1. gotten your *Photon 2* registered on the UC Berkeley IoT network, including the acquisition of your MAC address and the [addition of your device to the IoT network](https://portal.berkeley.edu/people/wifi_access).  If you have not, please do so based on the instructions found in [this tutorial](https://github.com/loopstick/Photon2_Tutorial/#2-configure-wi-fi-do-this-at-home)
1. compiled and flashed code to your *Photon 2* device, have experimented with making modifications in the Particle Web IDE, and have begun breadboarding with follow-along tutorials.  If you have not experimented with this, please go through the tutorial found [here](https://github.com/loopstick/Photon2_Tutorial/#7-hello-world---is-this-thing--on).

...if you've completed the tasks outlined above, please proceed!

---

#### Installing VS Code 

<div align="center"><img src="visual_studio_code.png"></img></div>

We are going to install Microsoft's Visual Studio Code (VS Code) integrated development environment (IDE).  This will allow us to integrate lots of other types of code outside of the Particle.io environment into the projects we are working on, and to explore alternate codebases that may intersect with what we're already doing with the Photon 2.  

It will also allow us to utilize the Particle.io platform within VS Code, which we will cover later.

1. Navigate to [the Visual Studio Code download page](https://code.visualstudio.com/Download) and download the software pertaining to your operating system.

1. Open the software application.  You'll notice that there is a sidebar on the left that displays options for selection.  This is the *Extensions* pane, which allows you to install extended portions of functionality into the Visual Studio code IDE.  It looks like this: <div align="center"><img src="extensions_pane.png"></img></div>

1. Click on this icon to expose the Extensions pane.  You'll note that your cursor pops into a field where you can search.

---

#### Installing particle workbench extension

1. Search for "Particle Workbench".  You'll note that a number of extensions pop up in the results.  The one that we will be installing is called "Workbench".  This includes some of the others that are displayed under a single installation.  

1. Click on the **Workbench** extension, and you'll see it pop up in a new tab to the right of the sidebar.  <div align="center"><img src="workbench_installer.png"></img></div>

1. Click on **Install** to install the extension.  This may take some time, depending on your internet connection.  You may also be prompted to install Command Line tools associated with features that the Particle Workbench needs.  Go ahead and say "yes" to these subsequent installations.  They are required for the Workbench to function.

#### Installing Serial monitor extension

We will need a serial monitor to verify that things are working in this tutorial.  This will allow us to print a "Hello World"-style output from the serial output of the device via USB.  

1. Click on the **Extensions** panel again.  It looks like this: <div align="center"><img src="extensions_pane.png"></img></div>

1. Search for "serial monitor".  There will be a Microsoft extension that shows up.  This is the one you want.  It looks like this: <div align="center"><img src="m_serial_monitor.png"></img></div>

1. Click on **Install** to install the extension. <div align="center" ><img width="80%" src="serial_monitor_installer.png"></img></div>


---

#### Sign in to Particle Workbench

1. Now that you've installed the Particle Workbench, you will see its icon in the left sidebar.  It looks like this: <div align="center"><img src="pw_extension_icon.png"></img></div>

1. Click on the extension to reveal the main Workbench page. <div align="center"><img src="workbench_main.png"></img></div>

1. Note that there are three **Getting Started** sections of this area.  "Launch Command Palette", "Login", and "Create a Project".  We'll go through each in succession to build and flash our first project, including some extra details that may not be covered by default.

---

open a folder containing demo project (include)

choose device os

choose device type

enter in device name or id

verify/compile

flash