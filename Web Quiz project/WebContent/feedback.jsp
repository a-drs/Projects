<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!doctype html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Alumni Feedback Form</title>

<link href="bootstrap.css" rel="stylesheet">
<link href="bootstrap.min.css" rel="stylesheet">
<style type="text/css">
	body{
	padding-top:30px;
	padding-bottom:30px;
}
</style>
</head>
<body>
<%
int flag=0;
String name,email;
name=new String("");
email=new String("");
name=request.getParameter("name");
email=request.getParameter("email");

//out.println(name);
%>

<div class="hero-unit">

<h1 align="center" >Welcome to <a class="btn btn-primary btn-large" href="welcome.jsp">PICT Feedback!&raquo;</a></h1>
</div>
<b>
Fields marked in <font color="Black" style="bold">*</font> are compulsory.
</b>
<br><br>

<center>
<div class="container" style="background-color:blue;">

<form >

Name : <input size ="50" type="text" name="name" <%if(name!=null)%>value=<%=name%>>
<%
try{
	if(name.equals("")){%><font color="black">*</font><%}
}
catch(Exception e)
{}
%>

	
<br><br>

Email Address : <input size="50" type="email" name="email" <%if(email!=null)%>value=<%=email%>/>
<%
try{
	if(email.equals("")){%><font color="black">*</font><%}
}

catch(Exception e)
{
	
}
%>
<br><br>
Select
<select>
<option value="BE">BE</option>
<option value="ME">ME</option>
</select>
<br><br>
Comments
<br>
<textarea rows="5" cols="50">
</textarea>
<br><br>


<input type="submit" name="submit">

<%

//name=request.getParameter("name");
email=request.getParameter("email");
name=request.getParameter("name");
out.println(name+"\n"+email);
try
{
if(!(email.equals("")|| name.equals("")))
{
	session.setAttribute("name", name);
	response.sendRedirect("welcome.jsp");
	flag=1;
}
else
{
	flag=0;
	
}
}
catch(Exception e)
{
	
}
%>

</form>
</div>
</center>
</body>
</html>