using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
	float distance = 10f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.RightArrow))
        {
        	if (transform.position.x < 110)
        		transform.Translate(distance, 0.0f, 0.0f);
        }
        if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
        	if (transform.position.x > 0)
        		transform.Translate(-distance, 0.0f, 0.0f);
        }
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
        	if (transform.position.y < 0)
	        	transform.Translate(0.0f, distance, 0.0f);
        }
        if (Input.GetKeyDown(KeyCode.DownArrow))
        {
        	if (transform.position.y > -90)
	        	transform.Translate(0.0f, -distance, 0.0f);
        }
    }




}
