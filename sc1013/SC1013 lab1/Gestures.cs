using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Leap;
using Leap.Unity;

public class Gestures : MonoBehaviour {

    public GameObject InstSphere;
    Controller controller;
    float deltaCloseFinger = 60f;
    float deltaAngleThumb = 45f;
    double generationInterval = 0.2;
    double timer = 0;
    Hand firstHand;

    // Use this for initialization
    void Start () {
        controller = new Controller();
    }
	
	// Update is called once per frame
	void Update () {
        
        Frame frame = controller.Frame();
        List<Hand> hands = frame.Hands;

        if (frame.Hands.Count > 0)
        {
            firstHand = hands[0];
            if (isThumbDirection(firstHand, Vector3.up) && checkFingerCloseToHand(firstHand))
            {
                timer = timer + Time.deltaTime; //Time.deltaTime is the interval between adjacent frames 
                if (timer >= generationInterval)
                {
                    Debug.Log ("Generation");
                    GameObject newobject = Instantiate(InstSphere, gameObject.transform.position + new Vector3(0f, 0.275f, 0f), gameObject.transform.rotation);
                    newobject.GetComponent<Rigidbody>().velocity = transform.TransformDirection(new Vector3(Random.Range(-1f,1f),1, Random.Range(-1f, 1f)) * 5);
                    timer = 0;
                }
            }
            else
            {
                timer = 0;
            }
        }
    }

    protected bool checkFingerCloseToHand(Hand hand)
    {
        List<Finger> listOfFingers = hand.Fingers;
        int count = 0;
        for (int f = 0; f < listOfFingers.Count; f++)
        {

            Finger finger = listOfFingers[f];
            if ((finger.TipPosition - hand.PalmPosition).Magnitude < deltaCloseFinger)
            {
                if (finger.Type == Finger.FingerType.TYPE_THUMB)
                {
                    return false;
                }
                else
                {
                    count++;
                }
            }
        }
        return (count == 4);
        return true;
    }

    protected bool isThumbDirection(Hand hand, Vector3 dir)
    {
        List<Finger> listOfFingers = hand.Fingers;
        for (int f = 0; f < listOfFingers.Count; f++)
        {
            Finger finger = listOfFingers[f];
            if (finger.Type == Finger.FingerType.TYPE_THUMB)
            {
                float angleThumbFinger = Vector3.Angle(
                                             UnityVectorExtension.ToVector3(finger.TipPosition - hand.PalmPosition), dir);
                if (angleThumbFinger < deltaAngleThumb)
                    return true;
                else
                    return false;
            }
        }
        return false;
        //return true;
    }
}
