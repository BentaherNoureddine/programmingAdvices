using System;
using System.Data.SqlClient;


namespace ContactsConsoleApp_Using_DB
{
    internal class Program
    {

        static string connectionString = "Server=.;Database=ContactsDB;User ID=sa;Password=123456";


        static void printContatcts(string startsWith)
        {
            // CREATE NEW CONNECTION OBJECT
            SqlConnection connection = new SqlConnection(connectionString);

            // CREATE AN SQL QUERY
            string queryText = "SELECT * FROM Contacts WHERE FirstName LIKE @startsWith + '%' ";
            Console.WriteLine(queryText);
            try
            {
                // OPEN CONNECTION TO THE DB
                connection.Open();

                // CREATE NEW COMMAND 
                SqlCommand getAllCOntactsCommand = new SqlCommand(queryText, connection);

                // ADD QUERY PARAMETER
                getAllCOntactsCommand.Parameters.AddWithValue("@startsWith", startsWith);

                // GET ALL THE DATA FROM THE SQL COMMAND AND PUT IT IN reader
                SqlDataReader reader = getAllCOntactsCommand.ExecuteReader();

               
                // CHECK IF WE HAVE ROWS 
                if (reader.HasRows)
                {
                    // LOOP INTO reader DATA
                    while (reader.Read())
                    {
                        int ContactID = (int)reader["ContactID"];
                        string FirstName = (string)reader["FirstName"];
                        string LastName = (string)reader["LastName"];
                        string Email = (string)reader["Email"];
                        string Address = (string)reader["Address"];
                        int CountryID = (int)reader["CountryID"];



                        Console.WriteLine($"ConatctID = {ContactID}\n");
                        Console.WriteLine($"FirstName = {FirstName}\n");
                        Console.WriteLine($"ConatctIF = {LastName}\n");
                        Console.WriteLine($"Email = {Email}\n");
                        Console.WriteLine($"Address = {Address}\n");
                        Console.WriteLine($"CountryID = {CountryID} \n");

                        Console.WriteLine("_________________________________________________\n");
                    }

                 
                  
                }
                else
                {
                    Console.WriteLine(" There are No Contacts");
                }

                //CLOSE THE CONNECTIONS
                reader.Close();
                connection.Close();


            }
            catch (Exception e)
            {
                Console.WriteLine("ERROR " + e.ToString());
            }
           



        }

        static void Main(string[] args)
        {

            printContatcts("j");
        }
    }
}
