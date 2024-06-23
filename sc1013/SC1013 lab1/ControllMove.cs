using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Leap;
using Leap.Unity;

public class ControllMove : MonoBehaviour {

    Controller controller;
    Hand firstHand;
    float deltaAngle = 25;
    float moveSpeed = 0.5f;
    float turnSpeed = 25f;

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        controller = new Controller();
        Frame frame = controller.Frame();
        List<Hand> hands = frame.Hands;
        if (frame.Hands.Count > 0)
        {
            firstHand = hands[0];
            Vector3 palmNormal = UnityVectorExtension.ToVector3(firstHand.PalmNormal);
            Vector3 handDirection = UnityVectorExtension.ToVector3(firstHand.Direction);

            //Move Object
            if (Vector3.Angle(palmNormal, new Vector3(0, -1, 1)) < deltaAngle)
            {
                transform.Translate(Vector3.forward * moveSpeed * Time.deltaTime);  //Forward
            }
            if (Vector3.Angle(palmNormal, new Vector3(0, -1, -1)) < deltaAngle)
            {
                transform.Translate(-Vector3.forward * moveSpeed * Time.deltaTime); //Backward
            }
        }
    }
}
