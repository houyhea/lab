//ต๗สิ
		var Debug={
			Trace:function(str)
			{
				var d=document.createElement("div");
				d.innerHTML=str + "---time:" + (new Date()).getTime();

				document.getElementById("debugInfo").appendChild(d);
			}

		}