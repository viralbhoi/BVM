<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <head>
                <title>Employee Information</title>
                <style>
                    table {border-collapse: collapse; width: 50%;}
                    th, td {border: 1px solid black; padding: 10px; text-align: left;}
                    th {background-color: lightgray;}
                </style>
            </head>
            <body>
                <h2>Employee Information</h2>
                <table>
                    <tr>
                        <th>Name</th>
                        <th>Department</th>
                        <th>Telephone</th>
                        <th>Email</th>
                    </tr>
                    
                    <xsl:for-each select="employee_info/employee">
                        <tr>
                            <td><xsl:value-of select="Name"/></td>
                            <td><xsl:value-of select="Department"/></td>
                            <td><xsl:value-of select="telephone"/></td>
                            <td><xsl:value-of select="email"/></td>
                        </tr>
                    </xsl:for-each>

                </table>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>
