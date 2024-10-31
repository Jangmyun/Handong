document.addEventListener("DOMContentLoaded", function () {
  const courseList = document.getElementById("course-list");
  const courseForm = document.getElementById("course-form");
  const bringCoursesBtn = document.getElementById("bring-courses");
  const courseUpdateForm = document.getElementById("course-update-form");
  const courseDeleteForm = document.getElementById("course-delete-form");
  const apiUrl = "http://localhost:3001/courses";

  console.log(courseList, courseForm, bringCoursesBtn);

  // 코스 목록 가져오기
  function fetchCourses() {
    fetch(apiUrl)
      .then((response) => response.json())
      .then((data) => {
        courseList.innerHTML = "";
        data.forEach((course) => {
          const courseItem = document.createElement("div");
          courseItem.innerText = `${course.id}: ${course.cname} (${course.code}) - ${course.credit} credits`;
          courseList.appendChild(courseItem);
        });
      });
  }

  // 새 코스 추가
  courseForm.addEventListener("submit", function (event) {
    event.preventDefault();

    const cname = document.getElementById("cname").value;
    const credit = document.getElementById("credit").value;
    const code = document.getElementById("code").value;

    const newCourse = { cname, credit, code };

    fetch(apiUrl, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(newCourse),
    }).then(() => {
      document.getElementById("cname").value = "";
      document.getElementById("credit").value = "";
      document.getElementById("code").value = "";
      fetchCourses();
    });
  });

  // 코스 수정
  courseUpdateForm.addEventListener("submit", function (event) {
    event.preventDefault();

    const id = document.getElementById("update-id").value;
    const cname = document.getElementById("update-cname").value;
    const credit = document.getElementById("update-credit").value;
    const code = document.getElementById("update-code").value;

    if (!id || (!cname && !credit && !code)) {
      alert("ID and Change is Required");
      return;
    }

    const updatedCourse = {};
    if (cname) updatedCourse.cname = cname;
    if (credit) updatedCourse.credit = credit;
    if (code) updatedCourse.code = code;

    fetch(`${apiUrl}/${id}`, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(updatedCourse),
    }).then(() => {
      document.getElementById("update-id").value = "";
      document.getElementById("update-cname").value = "";
      document.getElementById("update-credit").value = "";
      document.getElementById("update-code").value = "";
      fetchCourses();
    });
  });

  // 코스 삭제
  courseDeleteForm.addEventListener("submit", function (event) {
    event.preventDefault();

    const id = document.getElementById("delete-id").value;

    if (!id) {
      alert("ID is required!");
      return;
    }

    fetch(`${apiUrl}/${id}`, {
      method: "DELETE",
    }).then(() => {
      document.getElementById("delete-id").value = "";
      fetchCourses();
    });
  });

  // 페이지 로드 시 코스 목록 불러오기
  fetchCourses();
});
