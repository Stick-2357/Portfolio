// Declaration of class MyArc.
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;

public class MyArc 
{
   private double x1; // x coordinate of first endpoint
   private double y1; // y coordinate of first endpoint
   private double x2; // x coordinate of second endpoint
   private double y2; // y coordinate of second endpoint
   private double startAngle;
   private double arcAngle;
   private Color myColor; // Color of this arc
   private boolean filled; // whether this shape is filled
   private ArcType myClosure;

   // constructor initializes private variables with default values
   public MyArc() 
   {
      this(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ArcType.ROUND, Color.BLACK, false); // call constructor
   }

   // constructor with input values
   public MyArc(double x1, double y1, double x2, double y2, 
      double startAngle, double arcAngle, ArcType closure,
      Color color, boolean isFilled) 
   {
      setX1(x1); // set x coordinate of first endpoint
      setY1(y1); // set y coordinate of first endpoint
      setX2(x2); // set x coordinate of second endpoint
      setY2(y2); // set y coordinate of second endpoint
      setStartAngle(startAngle);
      setArcAngle(arcAngle);
      setClosure(closure);
      setColor(color); // set the color
      setFilled(isFilled);
   } 

   // set the x-coordinate of the first point
   public void setX1(double x1) 
   {
     this.x1 = (x1 >= 0.0 ? x1 : 0.0);
   }

   // get the x-coordinate of the first point
   public double getX1() 
   {
     return x1;
   }

   // set the x-coordinate of the second point
   public void setX2(double x2) 
   {
     this.x2 = (x2 >= 0.0 ? x2 : 0.0);
   }

   // get the x-coordinate of the second point
   public double getX2() 
   {
     return x2;
   }

   // set the y-coordinate of the first point
   public void setY1(double y1) 
   {
     this.y1 = (y1 >= 0.0 ? y1 : 0.0);
   }

   // get the y-coordinate of the first point
   public double getY1() 
   {
     return y1;
   }

   // set the y-coordinate of the second point
   public void setY2(double y2) 
   {
     this.y2 = (y2 >= 0.0 ? y2 : 0.0);
   }

   // get the y-coordinate of the second point
   public double getY2() 
   {
     return y2;
   }

   // set the y-coordinate of the second point
   public void setStartAngle(double startAngle) 
   {
     this.startAngle = (startAngle >= 0.0 ? startAngle : 0.0);
   }

   // get the y-coordinate of the second point
   public double getStartAngle() 
   {
     return startAngle;
   }
   
   // set the y-coordinate of the second point
   public void setArcAngle(double arcAngle) 
   {
     this.arcAngle = (arcAngle >= 0.0 ? arcAngle : 0.0);
   }

   // get the y-coordinate of the second point
   public double getArcAngle() 
   {
     return arcAngle;
   }
   
   // set the color
   public void setColor(Color color) 
   {
      myColor = color;
   } 

   // get the color
   public Color getColor() 
   {
      return myColor;
   } 
   
   // set the arcType
   public void setClosure(ArcType closure) 
   {
      myClosure = closure;
   } 

   // get the color
   public ArcType getClosure() 
   {
      return myClosure;
   } 
   
   // get upper left x coordinate
   public double getUpperLeftX() 
   {
      return Math.min(getX1(), getX2());
   } 

   // get upper left y coordinate
   public double getUpperLeftY() 
   {
      return Math.min(getY1(), getY2());
   }

   // get shape width
   public double getWidth() 
   {
      return Math.abs(getX2() - getX1());
   } 

   // get shape height
   public double getHeight() 
   {
      return Math.abs(getY2() - getY1());
   }
      
   // determines whether this shape is filled
   public boolean isFilled() 
   {
      return filled;
   } 
   
   // sets whether this shape is filled
   public void setFilled(boolean isFilled) 
   {
      filled = isFilled;
   } 
   
   // draws an arc in the specified color
   public void draw(GraphicsContext gc) 
   {      
      if (isFilled()) 
      {
         gc.setFill(getColor());
         gc.fillArc(getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight(), getStartAngle(),
            getArcAngle(), getClosure());
      }
      else 
      {
         gc.setStroke(getColor());
         gc.strokeArc(getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight(), getStartAngle(),
            getArcAngle(), getClosure());
      }
   }
}
