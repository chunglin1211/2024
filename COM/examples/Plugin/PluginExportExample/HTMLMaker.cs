//------------------------------------------------------------------
// Navisworks Sample code
//------------------------------------------------------------------
//
// (C) Copyright 2011 by Autodesk Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//------------------------------------------------------------------
// Navisworks API HTML Utility class
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;


namespace PluginExportExample
{
   class HTMLMaker
   {
      private String m_html;
      private String m_open_tag;

    public void StartHTML()
    {
       Debug.Assert(m_html == null);
       m_html = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/1999/REC-html401-19991224/loose.dtd\"> \n<HTML>\n<HEAD>\n<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; CHARSET=US-ASCII\">\n";
       m_open_tag = "<HEAD>";
    }

   public void AddTitle(String title )
   {
       if (m_open_tag.Equals("<HEAD>"))
           m_html += String.Format("<TITLE>{0}</TITLE>\n",title);
       else
           throw new ArgumentException("Open Tag is invalid");
   }

   public void AddStyleSheet(String stylesheet)
   {
       if (m_open_tag.Equals("<HEAD>"))
         m_html += String.Format("<LINK REL=\"StyleSheet\" HREF=\"{0}\" type=\"text/css\" media=\"screen\">\n",stylesheet);
       else
          throw new ArgumentException("Open Tag is invalid");
   }

   public void AddHeadline(String headline)
   {
       if (m_open_tag.Equals("<HEAD>"))
       {
           m_html += String.Format("</HEAD>\n<BODY>\n<H1>{0}</H1>\n", headline);
           m_open_tag = "<BODY>";
       }
       else
          throw new ArgumentException("Open Tag is invalid");
   }

   public void AddParagraph(String para)
   {
       if (m_open_tag.Equals("<BODY>"))
           m_html += String.Format("<P>{0}</P>\n",para);
       else
          throw new ArgumentException("Open Tag is invalid");
   }

   public void AddImage(String path, String desc)
   {
      m_html += String.Format("<IMG SRC=\"{0}\" ALT=\"{1}\">\n", path, desc);
   }

   public void AddRule()
   {
      m_html += "<HR SIZE=\"1\">\n";
   }

   public String GetHTML()
   {
       if (m_open_tag.Equals("<BODY>"))
       {
           m_html += "</BODY>\n</HTML>\n";
           m_open_tag = "";
       }
       return m_html;
   }
   public void AddSubHeading(String subheading)
   {
       if (m_open_tag.Equals("<BODY>"))
           m_html += String.Format("<H2>{0}</H2>\n", subheading);
       else
          throw new ArgumentException("Open Tag is invalid");
   }

   public void AddParagraphHeading(String para_heading)
   {
       if (m_open_tag.Equals("<BODY>"))
         m_html += String.Format("<H3>{0}</H3>\n", para_heading);
       else
          throw new ArgumentException("Open Tag is invalid");
   }

   }
}
