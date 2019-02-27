interface UserInterfcae {
    name: string;
    email: string;
    age: number;
    register(): void;
    payInvoice(): void;
}
class User implements UserInterfcae{
    public name: string;
    public email: string;
    public age: number;
    private uselessProperty: object;
    constructor(name: string, email: string, age: number){
        this.name = name;
        this.email = email;
        this.age = age;
        console.log("User Created " + this.name);
    }
    public register(): void{
        console.log(this.name + "is now registered");
    }
    public payInvoice(): void{
        console.log(this.name+ " paid invoice")
    }
    private checkUselessProperty(): object {
        return this.uselessProperty
    }
    public getUselessProperty(): object {
        return this.checkUselessProperty();
    }
}
class Member extends User {
    id: number;
    constructor(id: number, name: string, email: string, age: number) {
        super(name, email, age);
        this.id = id;
    }
    payInvoice(){
        super.payInvoice();
    }
}
let mike: User = new Member(1, "Mike Smith", "mike@gmail.com", 33);
mike.payInvoice();
