<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Questions</title>
<link href="css/bootstrap.css" rel="stylesheet">
<link href="css/bootstrap.min.css" rel="stylesheet">
</head>

<%@page import="java.sql.*" %>




<body>
<% 
	
String question=new String("");
String a,b,c,d,ans;
int flag=0;
a=new String("");
b=new String("");
c=new String("");
d=new String("");
ans=new String("");
String answer=new String("");
answer=request.getParameter("op");
try{
	
	Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
	System.out.println("driver");

	Connection con=DriverManager.getConnection("jdbc:odbc:somdeep", "", "");
	Statement st=con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
	ResultSet rs=st.executeQuery("select * from question where flag=0");
	
	
	rs.next();
	flag=rs.getInt("flag");
	
	if(flag!=0)
	{
	/*while(rs.next())
	{
	flag=rs.getInt("flag");
	if(flag==0)
	break;
	}*/
	}
	
	question=rs.getString("q");
	a=rs.getString("a");
	b=rs.getString("b");
	c=rs.getString("c");
	d=rs.getString("d");	
	ans=rs.getString("ans");
	System.out.println("ans:" +ans);
	try{
	
	rs.updateInt("flag", 1);
	rs.updateRow();
	rs.refreshRow();
	}
	catch(Exception e)
	{
	System.out.println("error");
	}
	flag=rs.getInt("flag");
	
	//System.out.println(flag);
		//question=rs.getString("question");
		
	%>


<div class="container-fluid" style="width: 1514px; ">
<div class="jumbotron" style="background-color:green; height: 334px; width: 1652px">
<h1><b>Question 1</b></h1><br>
<h2><b><%=question%></b></h2>
</div>
</div>


<div>
<form>
<ol>
	
     <li><input type="radio" name="op" value=<%=a%> > <%=a%></li>
	 <li><input type="radio" name="op" value=<%=b%> > <%=b%></li>
	 <li><input type="radio" name="op" value=<%=c%> > <%=c%></li>
	 <li><input type="radio" name="op" value=<%=d%> > <%=d%></li>
	<%
	
	answer=request.getParameter("op");
	st.close();
	con.close();;
	
	
}
catch(Exception e)
{
	
}

%>

</ol>
<center>

<input type="submit" class="btn btn-danger btn-lg" value="End Test">
<input type="hidden" name="hid" value=<%=ans%>>
<%
answer=request.getParameter("op");
ans=request.getParameter("hid");
out.println(answer);
out.println(ans);
try{
if(answer!=null)
{
session.setAttribute("op", answer);
response.sendRedirect("hidden.jsp");
}
 
 }
 catch(Exception e)
 {
 }
 %>
</center>
</form>
</div>

</body>
</html>