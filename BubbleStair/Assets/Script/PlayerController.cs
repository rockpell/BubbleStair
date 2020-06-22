using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

public class PlayerController : MonoBehaviour
{
    float distance = 10f;
    int[,] map = new int[10, 12]
    {{0, 48, 49, 50, 51, 52, 33, 34, 35, 36, 37, 38},
    {53, 54, 55, 56, 57, 58, 39, 42, 43, 44, 45, 46},
    {9, 10, 11, 12, 13, 32, 47, 59, 60, 61, 62, 63},
    {-1, -1, -1, -1, -1, -1, 64, 92, 94, 95, 96, 124},
    {40, 41, 91, 93, 123, 125, 126, -1, -1, -1, -1, -1},
    {97, 98, 99, 100, 101, 102, 65, 66, 67, 68, 69, 70},
    {103, 104, 105, 106, 107, 108, 71, 72, 73, 74, 75, 76},
    {109, 110, 111, 112, 113, 114, 77, 78, 79, 80, 81, 82},
    {115, 116, 117, 118, 119, 120, 83, 84, 85, 86, 87, 88},
    {121, 122, -1, -1, -1, -1, 89, 90, -1, -1, -1, -1}};
    string text = "";
    StreamWriter sw;

    // Start is called before the first frame update
    void Start()
    {
        sw = new StreamWriter(@"hoo.oO", false);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.RightArrow))
        {
            if (transform.position.x < 110)
            {
                transform.Translate(distance, 0.0f, 0.0f);
                text += 'o';
            }
        }
        if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            if (transform.position.y > -90)
            {
                transform.Translate(0.0f, -distance, 0.0f);
                text += 'O';
            }
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Debug.Log(map[(int)(-transform.position.y / 10), (int)(transform.position.x / 10)]);
            if (transform.position == Vector3.zero)
            {
                sw.Flush();
                sw.Close();
                Debug.Log("jinwoo is babo");
            }
            else
            {
                sw.WriteLine(text);
                text = text.Replace("o", " ");
                text = text.Replace("O", " ");
            }
            transform.position = new Vector3(0, 0, 0);

        }
    }
}
