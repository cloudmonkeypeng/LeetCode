public class User{
	String user_id;
	String user_name;
	int point;
	boolean has_buy;
	
	//string 用来发挥不同错误类型（是否有权利购买，扣除积分是否成功）
	String minusPoint(){}


	//更新是否购买
	String updateHasBuy(){}

}

public class Box{
	String box_id;
	boolean has_sell;
	
	//string 用来发挥不同错误类型（是否被抢光等）
	String minusBox(){}


	//更新是否卖出
	string updateHasSell(){}

}

public class Order{
	String user_id;
	String order_id;
	String box_id;

	//string 用来发挥不同错误类型
	String makeOrder(int user_id,int box_id){}
}

