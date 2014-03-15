wxNPR
=====
A minimalist news reader for NPR using their story api.

Dependencies
============
Development libraries for the following are required to compile this project.
+ curl
+ jsoncpp
+ boost_regex
+ boost_system
+ boost_thread
+ wxWidgets

Notes
=====
This application will first download the raw JSON api response and then read it back in. It will only be deleted if you press the "exit" button. The JSON files will <b>NOT</b> be deleted when the "x" button is pressed.
