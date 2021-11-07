/**
 * Ardity (Serial Communication for Arduino + Unity)
 * Author: Daniel Wilches <dwilches@gmail.com>
 *
 * This work is released under the Creative Commons Attributions license.
 * https://creativecommons.org/licenses/by/2.0/
 */

using UnityEngine;
using System.Threading;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using System;
using System.IO.Ports;

/**
 * Sample for reading using polling by yourself, and writing too.
 */
public class SampleUserPolling_ReadWrite : MonoBehaviour
{
    public SerialController serialController;
    public InputField input1, output1, enviada1, recibida1;

    // Initialization
    void Start()
    {
        serialController = GameObject.Find("SerialController").GetComponent<SerialController>();

       // Debug.Log("Press A or Z to execute some actions");
    }

    // Executed each frame
    void Update()
    {
        //---------------------------------------------------------------------
        // Send data
        //---------------------------------------------------------------------

        // If you press one of these keys send it to the serial device. A
        // sample serial device that accepts this input is given in the README.
       /* if (Input.GetKeyDown(KeyCode.A))
        {
            Debug.Log("Sending r");
            serialController.SendSerialMessage("r");
        }

        if (Input.GetKeyDown(KeyCode.Z))
        {
            Debug.Log("Sending w");
            serialController.SendSerialMessage("w");
        }*/


        //---------------------------------------------------------------------
        // Receive data
        //---------------------------------------------------------------------

        string message = serialController.ReadSerialMessage();

        if (message == null)
            return;

        // Check if the message is plain data or a connect/disconnect event.
        if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_CONNECTED))
            Debug.Log("Connection established");
        else if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_DISCONNECTED))
            Debug.Log("Connection attempt failed or disconnection detected");
        else
            Debug.Log("Message arrived: " + message);

        if (message != null)
        {
            recibida1.text = message;
        }

        if (message == "01")
        {
            output1.text = "NOT PULSED / ON";

        }
        else if (message == "11") 
        {
          output1.text = "PULSED / ON";
        }
        else if (message == "10")
        {
            output1.text = "PULSED / OFF";
        }
        else if (message == "00")
        {
            output1.text = "NOT PULSED / OFF";
        }



        //en ultima trama recibida muestro el mensaje,
    }


    public void SendR()
    {
        Debug.Log("Sending r");
        serialController.SendSerialMessage("r");
        input1.text = "r";
        enviada1.text = "r";
    }

    public void SendW()
    {
        Debug.Log("Sending w");
        serialController.SendSerialMessage("w");
        input1.text = "w";
        enviada1.text = "w";
    }
}
