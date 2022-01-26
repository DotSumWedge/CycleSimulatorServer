# RacingBoardGame
Board game where mechanics play out common strategies and ideas used in cycling such as drafting, attacking, pacing, sending teammates in early breakaways.

Todo:

    1. Setup development pipline for developing server side game logic in dll's
    2. Host website and create make a simple hello world page
    3. Create example of client side talking to server side
    4. Create database and have the client show something on the landing page
    5. Finish rough draft of core rules


One of the goals of this project is to learn how to better leverage dll's to improve the technical design of a web application.

An application can have multiple instances of itself running in the system simultaneously. A DLL can have only one instance.

An application can be loaded as a process. It can own things such as a stack, threads of execution, global memory, file handles, and a message queue. A DLL can't own these things.

A potential disadvantage to using DLLs is that the application isn't self-contained. It depends on the existence of a separate DLL module: one that you must deploy or verify yourself as part of your installation.

How to create a dll:
https://docs.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp?view=msvc-170
https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170#:~:text=To%20create%20a%20DLL%20project%20in%20Visual%20Studio,Library%20%28DLL%29%2C%20and%20then%20choose%20Next.%20See%20More.