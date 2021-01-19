write a factory class which defines a static method which will create instances of circle or square depending upon the type of shape we pass as parameter to this method.
for fruitful use of this shape factory let us define a client that will test any shapes that is gets by simply drawing it. 
client only bothers about the draw() member function defined for any shape instances.
to make sure any concrete derived classes of base class shpae will implement their own variant of draw member function, make base class's draw member function as pure virtual.
such a base class is also known as an abstract base class in c++.
client make use of this policy 