<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html class="no-js">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Hidden</title>
<script src="modernizr.js"></script>
</head>
<%!
String x,y;
%>
<%
x=new String("");
y=new String("");
x=request.getParameter("op");
y=request.getParameter("hid");
out.print(x+" "+y);
try
{
if(x.equalsIgnoreCase(y))
{

	response.sendRedirect("end.jsp");

}

else
{

	response.sendRedirect("questions.jsp");
}
}
catch(Exception e)
{

}
 %>

<body bgcolor="yellow">
<!DOCTYPE html>
<html>
<body>

<h1>My First JavaScript</h1>

<p id="demo">
JavaScript can change the content of an HTML element.
</p>

<script>
 
if (Modernizr.video) { 
	if(Modernizr.video.ogg)
	{
			alert("This browser supports HTML5 ogg video!");
	} 

	if(Modernizr.video.webm)
	{
			alert("This browser supports HTML5 webm video!");
	}
	if(Modernizr.video.h264)
	{
		alert("This browser supports HTML5 H264 video");
	} 
	

			else { alert("no canvas :(");}
}





function myFunction()
{
x = document.getElementById("demo"); //Find the element with id="demo"
x.innerHTML = "Hello JavaScript!";   //Change the HTML content
}
</script>

<button type="button" onclick="myFunction()">Click Me!</button>

</body>
</html>

</body>
</html>