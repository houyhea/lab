//ը������,���������Ҫ����TANK����ǰ�棬���Ⱥ�˳��
		Bomb=function(){
			this.Owner=null;
			this.Power=1;
			this.Speed=7;
		}
		Bomb.prototype=new Mover();
		Bomb.prototype.Load=function(x,y)
		{
			this.UI=document.getElementById("divMap").appendChild(document.createElement("div"));
			this.UI.className="bomb";
			this.SetPosition(x*40,y*40);
		}
	
		//��дOnHitTest����
		Bomb.prototype.OnHitTest=function(battleField)
		{
			var ex=new Explode();
			ex.Play(this.XPosition,this.YPosition);
			this.Owner.BombUsed-=1;
			battleField[this.YPosition][this.XPosition].occupier=null;
			UtilityClass.RemoveE(this.UI,document.getElementById("divMap"));

			var nextObj=this.GetNextBattleFieldCell(battleField);
			if(nextObj==null)
				return;
			nextObj.occupier=null;


			if(nextObj.obj instanceof Barrier)
			{
				//����ɱ�����
				if(nextObj.obj.CanBeAttacked)
				{
					nextObj.obj.DefendVal-=this.Power;
					if(nextObj.obj.DefendVal<=0)
					{
						var to=new EmptyB();
						to.UI=nextObj.obj.UI;
						to.XPosition=nextObj.obj.XPosition;
						to.YPosition=nextObj.obj.YPosition;
						nextObj.obj=to;
						to.UI.className="";
						battleField[this.YPosition][this.XPosition].obj.UI.className="";
					}
				}
			}
			
		}
	
		//��дHitTest����
		Bomb.prototype.HitTest=function(battleField)
		{
			var nextObj=this.GetNextBattleFieldCell(battleField);
			//Debug.Trace(nextObj instanceof Barrier);
			//if(nextObj instanceof Bomb)
				//Debug.Trace(this.XPosition+"--"+this.YPosition);
			if(nextObj==null)
			{
				return true;
			}
			//����Ƿ����ϰ���
			if(nextObj.obj instanceof Barrier)
			{
				if(nextObj.obj instanceof EmptyB)
				 {
					 //Debug.Trace("Empty");
					 if(nextObj.occupier instanceof Bomb)
					 {
						
						if(this.Owner instanceof SelfTank)
						{
							return nextObj.occupier.Owner instanceof EnimyTank;
						}
						else
						{
							return nextObj.occupier.Owner instanceof SelfTank;
						}
						
					 }
					 if(nextObj.occupier instanceof Tank)
					 {
						if(this.Owner instanceof SelfTank)
						{
							return nextObj.occupier instanceof EnimyTank;						
						}
						else
						{
							return nextObj.occupier instanceof SelfTank;
						}
					 }
				 }
				 //������ڵ������������ʹ���
				 if(this instanceof Bomb && nextObj.obj instanceof RiverB)
					 return false;
				 //Debug.Trace(nextObj.occupier instanceof Mover);
				 return !nextObj.obj.CanAcross;
			}

		}
		