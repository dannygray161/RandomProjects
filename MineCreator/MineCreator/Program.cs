using System;
using System.IO;
using System.IO.Compression;
using System.Text.Json;

/// <summary>
/// This is the main program class for the MineCreator application.
/// its first goal, is to create a single add on package for Minecraft Bedrock Edition
/// FIXME: add more details here

/// </summary>

public class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Starting Add-On Packager...");

        // --- 1. Define the Pack ---
        string packName = "MyTestPack";
        string packDescription = "My first C# generated pack!";

        // Get the path to your desktop
        string desktopPath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);

        // This is the working folder where we'll build the pack
        string buildFolderPath = Path.Combine(desktopPath, packName);

        // This is the final, importable file
        string mcpackFilePath = Path.Combine(desktopPath, $"{packName}.mcpack");

        // Clean up old files if they exist, so we can run this multiple times
        if (Directory.Exists(buildFolderPath))
        {
            Directory.Delete(buildFolderPath, true);
        }
        if (File.Exists(mcpackFilePath))
        {
            File.Delete(mcpackFilePath);
        }

        // Re-create the main pack directory
        Directory.CreateDirectory(buildFolderPath);

        // --- 2. Generate UUIDs (The "Magic") ---
        // This is the core "pain point" we are solving!
        string headerUuid = Guid.NewGuid().ToString();
        string moduleUuid = Guid.NewGuid().ToString();

        Console.WriteLine($"Generated Header UUID: {headerUuid}");
        Console.WriteLine($"Generated Module UUID: {moduleUuid}");

        // --- 3. Create the manifest.json content ---
        // This is a simplified C# object to hold the manifest data
        var manifest = new
        {
            format_version = 2,
            header = new
            {
                name = packName,
                description = packDescription,
                uuid = headerUuid,
                version = new[] { 1, 0, 0 },
                min_engine_version = new[] { 1, 16, 0 }
            },
            modules = new[]
            {
                new
                {
                    type = "data", // "data" means it does nothing, perfect for a test
                    uuid = moduleUuid,
                    version = new[] { 1, 0, 0 }
                }
            }
        };

        // Turn the C# object into a JSON string
        string jsonContent = JsonSerializer.Serialize(manifest, new JsonSerializerOptions { WriteIndented = true });

        // --- 4. Write the File ---
        string manifestPath = Path.Combine(buildFolderPath, "manifest.json");
        File.WriteAllText(manifestPath, jsonContent);

        Console.WriteLine($"Successfully created 'manifest.json' at {manifestPath}");

        // --- 5. Package the .mcpack (which is just a .zip) ---
        // This creates the final file you can double-click
        ZipFile.CreateFromDirectory(buildFolderPath, mcpackFilePath);

        Console.WriteLine($"\nSUCCESS! \nCreated '{mcpackFilePath}'");
        Console.WriteLine("You can now double-click this file to import it into Minecraft!");

        // Clean up the temporary build folder
        Directory.Delete(buildFolderPath, true);

        Console.WriteLine("\nPress any key to exit.");
        Console.ReadKey();
    }
}